<?php
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
    // 사용할 SQL문 생성
    $tournament_sql = "SELECT * FROM tournament";
    $dob_sql = "SELECT * FROM playerdob";
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TournamentDisplay.php</title>
</head>
<body>
    <h2>Handong Tennis Tournament</h2>
    
    <h3>Matches Year Winner</h3>
    <?php
        $result1 = $conn->query($tournament_sql);
        if($result1->num_rows > 0)
        {
            while($row = $result1->fetch_assoc()) {
                echo $row['Tournament']." ".$row['Year']." ".$row['Winner']."<br/>";
            }
        }
        else
        {
            echo "There is no data in table 'tournament'";
        }
    ?>

    <h3>Player DOB</h3>
    <?php
        $result2 = $conn->query($dob_sql);
        if($result2->num_rows > 0)
        {
            while($row = $result2->fetch_assoc()) {
                echo $row['Player']." ".$row['DOB']."<br/>";
            }
        }
        else
        {
            echo "There is no data in table 'playerdob'";
        }
        echo '<h3><a href="lastprj.html">Home Site</a></h3>';
    ?>
</body>
</html>