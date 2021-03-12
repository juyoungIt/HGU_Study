<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TennisTournament.php</title>
    <link rel="stylesheet" href="TennisTournament.css"/>
</head>
<body>
    <!-- 해당 페이지의 제목을 표현하는 부분 -->
    <div id="title">
        Tournament Winner
    </div>

    <!-- 해당 페이지의 왼쪽 영역 부분 -->
    <div id="left">
        <p id="left_title">Table for Tournament Winner</p>
        <!-- 사용자에게 값을 입력받는 form 부분 -->
        <div id="form_container">
            <form id="left_form" action="TournamentWinnerTable.php" method="POST">
                <label for="tournament">Tournament: </lable>
                <input type="text" name="tournament"/><br />
                <label for="year">Year: </label>
                <input type="text" name="year" /><br />
                <label for="winner">Winner: </label>
                <input type="text" name="winner" /><br />
                <br/>
                <input id="sButton1" type="submit" value="submit"/>
            </form>
        </div>

        <!-- 다시 원래 홈페이지로 돌아가는 부분 -->
        <div id="return_home">
            <a href="lastprj.html">Home Site</a><br />
        </div>

        <!-- 좌우로 움직이는 애니메이션이 적용된 이미지 -->
        <img src="sports.png" />
    </div>

    <!-- 해당 페이지의 오른쪽 영역 부분 -->
    <div id="right">
        <p id="right_title1">Tennis<br/>Tournament</p>
        <p id="right_title2">Winner Date of Birth</p>
        <form id="right_form" action="PlayerDOB.php" method="POST">
            <label for="player">Player: </label>
            <input type="text" name="player"/><br/>
            <label for="birth">Date of Birth</label>
            <input type="text" name="birth" /><br/>
            <br/>
            <input type="submit" value="submit" />
        </form>
    </div>

    <!-- 페이지의 footer 영역부분 -->
    <div id="footer">
        Handong Tennis Tournament
    </div>
</body>
</html>