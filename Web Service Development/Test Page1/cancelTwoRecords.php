<?php
    // DB와의 연결을 위해 필요한 값들을 사전에 선언 
    $server_name = "localhost";  // 서버명
    $user_name = "root";         // 사용자 명
    $password = "";              // 비밀번호
    $db_name = "homework";       // 사용하는 DB명

    // DB와의 Connection을 형성
    $conn = new mysqli($server_name, $user_name, $password, $db_name);
    // DB와의 Connection을 점검
    if($conn->connect_error) {
        die("Connection Failed: ".$conn->connect_error);
    }
    // 해당 페이지에서 사용하는 sql문을 생성
    // 값을 읽어오는 것과 관련된 sql문을 생성 및 전달
    $readTournament_sql = "SELECT * FROM tournament";
    $readPlayerdob_sql = "SELECT * FROM playerdob";
    // 값을 삭제하는 것과 관련된 sql문을 생성 (prepared statement)
    $deleteTournament_sql = $conn->prepare("DELETE FROM tournament WHERE Tournament=? AND Year=?");
    $deletePlayerdob_sql = $conn->prepare("DELETE FROM playerdob WHERE Player=?");

    // form을 통해 전달받은 데이터가 있는 지 확인하는 부분 - 1
    if(isset($_POST['tournament_delete'])){
        $data_check1 = $_POST['tournament_delete'];
        $searchValue = explode("/", $data_check1);
        $deleteTournament_sql->bind_param("si", $searchValue[0], $searchValue[1]);
        $deleteTournament_sql->execute();
    }
    // form을 통해 전달받은 데이터가 있는 지 확인하는 부분 - 2
    if(isset($_POST['playerdob_delete'])) {
        $data_check2 = $_POST['playerdob_delete'];
        $deletePlayerdob_sql->bind_param("s", $data_check2);
        $deletePlayerdob_sql->execute(); // 이 부분이 쿼리문이 전송되지 않는 상황
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>cancelTwoRecords.php</title>
    <link rel="stylesheet" href="cancelTwoRecords.css" />
</head>
<body>
    <!-- 해당 페이지의 제목을 표시하는 부분 -->
    <header>
        Local Tennis Tournament
    </header>

    <!-- 해당 페이지의 왼쪽 영역 -->
    <div id="left">
        <!-- 왼쪽 영역의 첫번째 제목 부분 -->
        <?php
            $rt_result = $conn->query($readTournament_sql);
            // DB에 읽어올 수 있는 데이터가 존재하고,
            // form을 통해서 전달받은 데이터가 존재하는 경우
            if(!isset($data_check1) && !isset($data_check2)) {
                echo '<p id="before_left_title1">Delete Tournament</p>';
                echo '<form id="form1" method="POST">';
                echo '<label for="tournament_delete">Select a Record to Delete:</label><br />';
                echo '<select id="tournament_select" type="option" name="tournament_delete"><br/>';
                echo '<option value="#">-- Select One --</option>';
                while($row = $rt_result->fetch_assoc()) {
                    // Tournament와 Year값을 value로 전달
                    echo '<option value="'.$row["Tournament"]."/".$row["Year"].'">'
                        .$row["Tournament"]." ".$row["Year"]." ".$row["Winner"]."</option>";
                }
                echo '</select><br />';
                echo '<input type="submit" value="Delete Selected Entry" />';
                echo '</form>';
            }
            // form을 통해서 전달받은 데이터가 존재하는 경우
            else if(isset($data_check1) || isset($data_check2)) {
                echo '<p id="after_left_title1">Record&#40;s&#41; Deleted</p>';
                echo '<p>Would you like to <a href="cancelTwoRecords.php">delete another</a>?</p>';
            }
        ?>

        <!-- 왼쪽 영역의 두번째 제목 부분 -->
        <?php
            $rp_result = $conn->query($readPlayerdob_sql);
            // DB에 읽어올 수 있는 정보가 존재하고,
            // form을 통해서 전달받은 데이터가 존재하는 경우
            if(!isset($data_check1) && !isset($data_check2)) {
                echo '<p id="before_left_title2">Delete Player DOB</p>';
                echo '<form id="form2" method="POST">';
                echo '<label for="playerdob_delete">Select a Record to Delete:</label><br />';
                echo '<select id="playerdob_select" type="option" name="playerdob_delete"><br/>';
                echo '<option value="#">-- Select One --</option>';
                while($row = $rp_result->fetch_assoc()) {
                    echo '<option value="'.$row["Player"].'">'.$row["Player"]." ".$row["DOB"]."</option>";
                }
                echo '</select><br />';
                echo '<input type="submit" value="Delete Selected Entry" />';
                echo '</form>';
            }
            // form을 통해서 아직 전달받은 데이터가 존재하지 않는 경우
            else if(isset($data_check1) || isset($data_check2)) {
                echo '<p id="after_left_title1">Record&#40;s&#41; Deleted</p>';
                echo '<p>Would you like to <a href="cancelTwoRecords.php">delete another</a>?</p>';
            }
        ?>

        <!-- 다시 초기 페이지로 이동하기 위한 링크 -->
        <div id="returnHome">
            <a href="lastprj.html">Home Site</a>
        </div>
        <!-- 애니메이션 효과가 적용되는 이미지에 대한 영역 -->
        <div id="imageBox"></div>
    </div>





    <!-- 해당 페이지의 오른쪽 영역 -->
    <div id="right">
        <!-- 오른쪽 영역의 제목 부분 -->
        <p id="right_title">Pohang Tennis<br/>Tournament</p>

        <!-- 오른쪽 영역의 첫번째 부제목 부분 -->
        <h1 id="subtitle1">Senior Tennis Match</h1>
        <!-- 오른쪽 영역의 첫번째  내용 부분 -->
        <p id="content1">Senior tennis match is held twice per year for people over 70 years old.</p>

        <!-- 오른쪽 영역의 두번째 부제목 부분 -->
        <h1 id="subtitle2">Handong Tennis Tournament</h1>
        <!-- 오른쪽 영역의 두번째 내용 부분 -->
        <p id="content2">With the Handong Tennis Tournament, all the freshment from Kyungbuk area universities are invited.</p>

        <!-- 위치가 지속적으로 움직이는 이미지 -->
        <div id="moveImage">
            <img src="moveImage.png" />
        </div> 

        <!-- 웹 페이지 상에서 움직이는 텍스트 상자 -->
        <div id="textBox">
            Apply Junior Tennis Match,<br/>
            January 15 2021
        </div>
    </div>

    <!-- 해당 페이지의 footer 영역 -->
    <footer>
        Handong Tennis Club
    </footer>

    <!-- 웹 페이지 상에서 움직이는 다른 데이터 -->
</body>
</html>