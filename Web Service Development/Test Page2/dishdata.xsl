<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
<html>
<style>
    p {
        font-size: 18px;
        font-weight: bold;
        color: purple;
        margin-top: 60px;
    }

    h1 {
        width: 480px;
        padding: 5px;
        border: 1px solid blue;
        text-shadow: 3px 3px 1px red;
    }
    h2 {
        width: 150px;
        height: 30px;
        padding-top: 7px;
        background-color: cyan;
        box-sizing: border-box;
    }
    ul {
        width: 380px;
        padding-top: 5px;
        padding-bottom: 5px;
        background-color: orange;
    }

    h2#appetizer {
        transition: width 2s, height 2s, transform 2s;
    }

    h2#appetizer:hover {
        width: 280px;
        height: 100px;
        font-size: 30px;
        color: purple;
        background-color: lightgray;
        border: 2px solid red;
        transform: rotate(180deg);
    }

    h2#soup {
        position: relative;
    }

    h2#soup:hover {
        width: 280px;
        height: 100px;
        font-size: 30px;
        color: purple;
        background-color: lightgray;
        animation: myfirst 4s infinite;
    }

    @keyframes myfirst {
        0%   {left: 0px;}
        50% {left: 100px}
        100% {left: 0px;} 
    }

    h2#fish:hover{
        font-size: 30px;
        color: red;
        background-color: green;
        text-align: center;
        transform: skewY(20deg);
    }

    h2#pasta {
        transition: width 2s, height 2s;
    }

    h2#pasta:hover {
        width: 280px;
        height: 100px;
        font-size: 30px;
        color: blue;
        background-color: lightgray;
    }

    h2#entree:hover {
        width: 200px;
        height: 50px;
        padding: 10px;
        font-size: 30px;
        color: blue;
        background-color: yellow;
        text-align: center;
        text-shadow: 3px 3px 1px red;
    }

    h2#dessert:hover {
        width: 200px;
        height: 50px;
        padding-top: 10px;
        padding-bottom: 10px;
        font-size: 30px;
        text-align: center;
        color: blue;
        background-color: lightgray;
        transform: skewX(20deg);
    }
</style>
<body>
    <h1>Specials -- <xsl:value-of select="special-menu/menu-date" /></h1>

    <h2 id="appetizer">Appetizer</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-appetizer" /></li>
        <li>Price: <xsl:value-of select="special-menu/special-appetizer/@price" /></li>
    </ul>

    <h2 id="soup">Soup</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-soup" /></li>
        <li><xsl:value-of select="special-menu/special-soup/@price" /></li>
    </ul>

    <h2 id="fish">Fish</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-fish" /></li>
        <li><xsl:value-of select="special-menu/special-fish/@price" /></li>
    </ul>

    <h2 id="pasta">Pasta</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-pasta" /></li>
        <li><xsl:value-of select="special-menu/special-pasta/@price" /></li>
    </ul>

    <h2 id="entree">Entree</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-meat" /></li>
        <li><xsl:value-of select="special-menu/special-meat/@price" /></li>
    </ul>

    <h2 id="dessert">Dessert</h2>
    <ul>
        <li><xsl:value-of select="special-menu/special-sweet" /></li>
        <li><xsl:value-of select="special-menu/special-sweet/@price" /></li>
    </ul>

    <p>Special menus are available every day from opening until noon.
    <br /><br />Welcome your visit!</p>
</body>
</html>
</xsl:template>
</xsl:stylesheet>