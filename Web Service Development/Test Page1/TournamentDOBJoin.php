<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TournamentDOBJoin.php</title>
</head>
<body>
    <h1>database join</h1>
    <h2><i>Join Operation</i></h2>
    <?php
        // DB와의 Connection을 생성
        $conn = new mysqli("localhost", "root", "", "homework");
        // DB와의 Connection을 점검
        if($conn->connect_error) {
            die("Connection Failed: ".$conn->connect_error);
        }
        // 사용할 SQL문 생성
        $sql = "SELECT * FROM tournament inner join playerdob on tournament.Winner=playerdob.Player";
        $result = $conn->query($sql);
        // table join 및 조회결과를 화면에 출력
        if($result->num_rows > 0)
        {
            while($row = $result->fetch_assoc()) {
                echo $row['Tournament']." ".$row['Year']." ".$row['Winner']." ".$row['DOB']."<br/>";
            }
        }
        else
        {
            echo "There is no information about Tournament<br/>";
        }
        // DB와의 연결을 종료함
        $conn->close();
    ?>
    <h2><a href="lastprj.html">Home Site</a><h2>
</body>
</html>