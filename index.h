const char INDEX_START[] PROGMEM = R"=====(
<!DOCTYPE html>
<head>
    <title>Main page</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width = device-width, initial-scale = 1.0, maximum-scale = 1.0">
    <link href="all.css" rel="stylesheet">
    <style>
        body {
            background-color: #F7F9FD;
        }
        .container {
            width: 20rem;
            margin-left: auto;
            margin-right: auto;
        }
        .center {
            text-align: center;
        }
        .m_left {
            margin-left: 1rem;
        }
        .m_bottom {
            margin-bottom: 3rem;
        }
        .link {
            display: block;
            width: 100%;
            padding: 1rem 0rem;
            border-radius: 0.5rem;
            background-color: #DA5868;
            font-family: 'Montserrat', sans-serif;
            font-size: 11pt;
            letter-spacing: 0.05rem;
            text-align: center;
            font-weight: bold;
            text-decoration: none;
            outline: none;
            color: white;
        }
        .link:hover {
            background-color: #CD3341;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1 class="center">
                <font color="#DA5868">Hello!</font>
            </h1>
            <h3 class="center">[ Hostname ]</h3>
)=====";

const char INDEX_END[] PROGMEM = R"=====(
        </div>
        <div class="menu">
            <br>
            <a class="link" href="toggle">Toggle</a>
            <br>
            <a class="link" href="/">Refresh</a>
            <br>
            <a class="link" href="reset">Reboot module</a>
            <br>
            <br>
            <p><font color="#6D6D6D">Натисніть <font color="#DA5868">Refresh</font>, щоб оновити інформацію на сторінці.</font></p>
            <p><font color="#6D6D6D">Натисніть <font color="#DA5868">Reboot</font>, щоб перезавантажити модуль.</font></p>
        </div>
    </div>
</body>
</html>
)=====";
