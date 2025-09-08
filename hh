<!-- Grupo: Bismark, Gerard, Guilherme Giovanetti, Gustavo Batista e Kaua Rubbo -->

<!DOCTYPE html>
<html>

<head>
  <meta charset="UTF-8">
  <title>Calculadoras</title>
  <style>
    body {
      gap: 5px;
      display: flex;
      flex-direction: column;
      font-family: Arial, sans-serif;
    }

    .calculadora {
      display: flex;
      background-color: rgb(165, 165, 165);
      width: 280px;
      padding: 10px;
      flex-direction: column;
      align-items: center;
      border: 5px solid grey;
      margin-bottom: 40px;
    }

    .botoes {
      display: grid;
      grid-template-columns: repeat(4, 1fr);
      gap: 10px;
      width: 100%;
    }

    .input input {
      width: 90%;
      height: 50px;
      font-size: 36px;
      text-align: left;
      margin-bottom: 10px;
      padding: 10px;
    }

    button {
      font-size: 20px;
      padding: 10px;
      border-radius: 10px;
    }

    .operadores {
      background-color: yellow;
      padding: 10px;
      border-radius: 10px;
      margin: 5px;
    }

    .numeros {
      background-color: violet;
      padding: 10px;
      border-radius: 10px;
      margin: 5px;
    }

    .clear {
      background-color: #EE5000;
      padding: 10px;
      border-radius: 10px;
      margin: 5px;
    }

    button:hover {
      background-color: lightblue;
    }

    .linha {
      display: flex;
      align-items: center;
      margin-bottom: 5px;
    }

    .linha input.valor {
      width: 60px;
      height: 30px;
      font-size: 14px;
      text-align: center;
      margin: 0 3px;
      background: #EEE;
      border: 1px solid #CCC;
      border-radius: 3px;
    }

    .linha input.resultado {
      width: 80px;
      height: 30px;
      font-size: 10px;
      text-align: center;
      margin: 0 3px;
      background: #EEE;
      border: 1px solid #CCC;
      border-radius: 3px;
    }

    .btn.operador {
      width: 37px;
      height: 37px;
      margin: 0 3px;
      border: none;
      color: white;
      font-size: 18px;
      cursor: pointer;
      border-radius: 5px;
      background: #FF8000;
    }

    button.btn.operador:hover {
      background: #EE5000;
    }

    .btn.limpar {
      width: 50px;
      height: 37px;
      margin-left: 5px;
      border: none;
      border-radius: 5px;
      background: orange;
      color: white;
      font-size: 10px;
      cursor: pointer;
    }

    button.btn.limpar:hover {
      background: #EE5000;
    }

    .igual {
      margin: 0 3px;
      font-size: 18px;
    }
  </style>
</head>

<body>

    <div class="container1">
    <div class="calculadora">
      <div class="input">
        <input type="text" readonly maxlength="12" id="display">
      </div>
      <div class="botoes">
        <button class="numeros">7</button>
        <button class="numeros">8</button>
        <button class="numeros">9</button>
        <button class="operadores">/</button>
        <button class="numeros">4</button>
        <button class="numeros">5</button>
        <button class="numeros">6</button>
        <button class="operadores">*</button>
        <button class="numeros">1</button>
        <button class="numeros">2</button>
        <button class="numeros">3</button>
        <button class="operadores">-</button>
        <button class="numeros">0</button>
        <button class="clear">AC</button>
        <button class="operadores">=</button>
        <button class="operadores">+</button>
      </div>
    </div>
  </div>

    <div class="linha">
    <input id="soma1" type="number" class="valor">
    <input id="soma2" type="number" class="valor">
    <button id="btsoma" class="btn operador plus">+</button>
    <span class="igual">=</span>
    <input id="soma3" type="text" class="resultado" readonly value="Resultado">
    <button class="btn limpar">Limpar</button>
  </div>

  <div class="linha">
    <input id="sub1" type="number" class="valor">
    <input id="sub2" type="number" class="valor">
    <button id="btsub" class="btn operador">-</button>
    <span class="igual">=</span>
    <input id="sub3" type="text" class="resultado" readonly value="Resultado">
    <button class="btn limpar">Limpar</button>
  </div>

  <div class="linha">
    <input id="mult1" type="number" class="valor">
    <input id="mult2" type="number" class="valor">
    <button id="btmult" class="btn operador">*</button>
    <span class="igual">=</span>
    <input id="mult3" type="text" class="resultado" readonly value="Resultado">
    <button class="btn limpar">Limpar</button>
  </div>

  <div class="linha">
    <input id="div1" type="number" class="valor">
    <input id="div2" type="number" class="valor">
    <button id="btdiv" class="btn operador">/</button>
    <span class="igual">=</span>
    <input id="div3" type="text" class="resultado" readonly value="Resultado">
    <button class="btn limpar">Limpar</button>
  </div>

  <script>
    
    const display = document.querySelector("#display");
     // Seleciona todos os botões
    const botoes = document.querySelectorAll(".botoes button");
    // Para cada um dos botões, adiciona evento de clique
    botoes.forEach(btn => {
      btn.addEventListener("click", () => {
        const val = btn.textContent;

        if (val === "AC") {
          display.value = "";
        } else if (val === "=") {
          try {
          // EVAL é permitido aqui porque:
          // 1) O exercício é apenas didático e controlado (não há entrada de usuário malicioso).
          // 2) Facilita avaliar operações sem criar um parser manual.
          // 3) Em aplicações reais, eval NÃO deve ser usado por questões de segurança.
            display.value = eval(display.value);
          } catch {
            display.value = "Erro";
          }
        } else {
          if (display.value.length < 12) {
            display.value += val;
          }
        }
      });
    });
    //BOTAO LIMPAR DAS LINHAS
    document.querySelectorAll(".limpar").forEach(btn => {
      btn.addEventListener("click", () => {
        const linha = btn.parentElement;
        linha.querySelectorAll("input").forEach(input => input.value = "");
        linha.querySelector(".resultado").value = "Resultado";
      });
    });
    //OPERACOES DAS LINHAS (SOMA, SUB, MULT, DIVISAO)
    document.querySelectorAll(".operador").forEach(btn => {
      btn.addEventListener("click", () => {
        const linha = btn.parentElement;
        const valores = linha.querySelectorAll(".valor");

        //SE O CAMPO ESTIVER VAZIO, CONSIDERA 0
        const v1 = parseFloat(valores[0].value) || 0;
        const v2 = parseFloat(valores[1].value) || 0;
        let resultado = "";

        if (!isNaN(v1) && !isNaN(v2)) {
          switch (btn.textContent) {
            case "+": resultado = v1 + v2; break;
            case "-": resultado = v1 - v2; break;
            case "*": resultado = v1 * v2; break;
            case "/": resultado = v2 === 0 ? "Erro" : (v1 / v2).toFixed(2); break;
          }
        }
        linha.querySelector(".resultado").value = resultado || "Resultado";
      });
    });
  </script>
</body>
</html>

