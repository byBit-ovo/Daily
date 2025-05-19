function checkUser() {
    const name = document.getElementById("name").value.trim();
    const birthdate = document.getElementById("birthdate").value;
    const resultDiv = document.getElementById("result");
  
    if (!birthdate) {
      resultDiv.textContent = "请输入出生日期。";
      return;
    }
  
    const zodiac = getZodiac(birthdate);
    const character = getCharacter(name || birthdate);
  
    resultDiv.innerHTML = `🌟 你的星座是：<strong>${zodiac}</strong><br>🧠 人品分析：<strong>${character}</strong>`;
  }
  
  function getZodiac(dateStr) {
    const date = new Date(dateStr);
    const month = date.getMonth() + 1;
    const day = date.getDate();
  
    const zodiacSigns = [
      ["摩羯座", 1, 19], ["水瓶座", 2, 18], ["双鱼座", 3, 20],
      ["白羊座", 4, 19], ["金牛座", 5, 20], ["双子座", 6, 20],
      ["巨蟹座", 7, 22], ["狮子座", 8, 22], ["处女座", 9, 22],
      ["天秤座", 10, 22], ["天蝎座", 11, 21], ["射手座", 12, 21],
      ["摩羯座", 12, 31]
    ];
  
    for (let i = 0; i < zodiacSigns.length; i++) {
      const [sign, m, d] = zodiacSigns[i];
      if ((month === m && day <= d) || (month === m - 1 && day > zodiacSigns[i - 1]?.[2])) {
        return sign;
      }
    }
    return "未知星座";
  }
  
  function getCharacter(input) {
    const score = [...input].reduce((acc, char) => acc + char.charCodeAt(0), 0) % 5;
    const traits = [
      "你是一个超级善良的人，充满正能量🌈！",
      "你机智幽默，朋友都喜欢和你在一起😄。",
      "你低调内敛，但关键时刻总能站出来👏。",
      "你极具创造力，是个天生的艺术家🎨。",
      "你逻辑超强，适合做战略大师♟️。"
    ];
    return traits[score];
  }
  