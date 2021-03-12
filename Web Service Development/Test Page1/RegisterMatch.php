<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="RegisterMatch.css" />
    <title>RegisterMatch.php</title>
</head>
<body>
    <!-- 페이지의 header 영역에 대한 부분 -->
    <div id="header">
        Register Upcoming Event
    </div>

    <!-- 페이지의 Subheader 영역에 대한 부분 -->
    <div id="subheader">
        Input your name, city, and DOB
    </div>

    <!-- 페이지의 form 영역에 대한 부분 -->
    <div id="formContainer">
        <form action="RegisterEvent.php" method="POST">
            <label for="name">Name: </label>
            <input type="text" name="name" /><br/>
            <label for="city">City: </label>
            <input type="text" name="city" /><br/>
            <label for="dob">DOB: </label>
            <input type="text" name="dob" /><br/>
            <br/>
            <input type="submit" value="submit" />
        </form>
    </div>

    <!-- Home 페이지로 돌아가는 링크가 위치하는 부분 -->
    <div id="returnHome">
        <a href="lastprj.html">Home Site</a>
    </div>

    <!-- 페이지의 footer 영역에 대한 부분 -->
    <div id="footer">
        Freshmen Tournament
    </div>
</body>
</html>