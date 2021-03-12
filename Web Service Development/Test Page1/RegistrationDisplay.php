<?php
    // DB와의 연결을 위한 정보설정
    $server_name = "localhost";
    $user_name = "root";
    $password = "";
    $db_name = "homework";

    // DB와의 Connection을 형성
    $conn = new mysqli($server_name, $user_name, $password, $db_name);
    // DB와의 Connection을 점검
    if($conn->connect_error) {
        die("Connection Failed: ".$conn->connect_error);
    }

    // 사용할 SQL문 생성 및 DB 전달
    $sql = "SELECT * FROM registermatch";
    $result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RegistrationDisplay.php</title>
</head>
<body>
    <h1>Upcoming Tennis Tournament</h1>
    <h2>Name   City   DOB</h2>
    <?php
        // 앞에서 생성하여 실행한 SQL문 실행결과에 따른 조건부 처리
        if($result == TRUE) {
            while($row = $result->fetch_assoc()) {
                echo $row['Name']." ".$row['City']." ".$row['DOB']."<br />";
            }
        }
        else {
            echo "Connot find data from table 'registermatch'<br/>";
        }
    ?>
    <h2><a href="lastprj.html">Home Stie</a></h2>
</body>
</html>