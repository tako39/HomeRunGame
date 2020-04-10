<?php

// DBに接続
$mysql = mysqli_connect('localhost', 'root', '') or die(mysqli_error($mysql));
mysqli_select_db($mysql, 'konami_kadai1') or die(mysqli_error($mysql));
mysqli_query($mysql, 'SET NAMES UTF8') or die(mysqli_error($mysql));

// スコアを登録
if(isset($_POST['score'])){
	$score = intval($_POST['score']);
	$query = sprintf('INSERT INTO ranking SET score=%d',
			mysqli_real_escape_string($mysql, $score));
	mysqli_query($mysql, $query) or die(mysqli_error($mysql));;
	
	$request = sprintf('SELECT r1.No, r1.Score,
			(SELECT COUNT(r2.Score) FROM ranking AS r2
			 WHERE r2.Score > r1.Score)+1 AS Rank
			 FROM ranking AS r1
			 ORDER BY r1.No DESC
			 LIMIT 1;'); 
}
// ランキングを取得
else{
	$request = sprintf('SELECT r1.No, r1.Score,
			(SELECT COUNT(r2.Score) FROM ranking AS r2
			 WHERE r2.Score > r1.Score)+1 AS Rank
			 FROM ranking AS r1
			 ORDER BY r1.Score DESC
			 LIMIT 10;');
}

$ranking = mysqli_query($mysql, $request) or die(mysqli_error($mysql));;

//　返信データ
$response = array();
	while($row = mysqli_fetch_assoc($ranking)){
		$response[] = array(
			'No'=>$row['No'],
			'Score'=>$row['Score'],
			'Rank'=>$row['Rank']
		);
	}

// jsonで出力
$jsonData = json_encode($response);
header("Content-Type: application/json; charset=utf-8");
echo $jsonData;
?>