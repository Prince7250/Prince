const cells = document.querySelectorAll('.cell');
const statusText = document.querySelector('.status');
const restartBtn = document.getElementById('restart');
const menu = document.getElementById('menu');
const gameContainer = document.getElementById('game');
const vsBotBtn = document.getElementById('vsBot');
const vsPlayerBtn = document.getElementById('vsPlayer');
let currentPlayer = 'X';
let gameActive = true;
let board = ['', '', '', '', '', '', '', '', ''];
let isBotGame = false;

const winConditions = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
];

// Função MiniMax para calcular o melhor movimento
function minimax(board, depth, isMaximizing) {
    let score = checkWinner();
    if (score !== null) {
        return score; // Retorna o valor de pontuação do estado final
    }
    
    if (isMaximizing) {
        let bestScore = -Infinity;
        for (let i = 0; i < board.length; i++) {
            if (board[i] === '') {
                board[i] = 'O';
                let score = minimax(board, depth + 1, false);
                board[i] = '';
                bestScore = Math.max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        let bestScore = Infinity;
        for (let i = 0; i < board.length; i++) {
            if (board[i] === '') {
                board[i] = 'X';
                let score = minimax(board, depth + 1, true);
                board[i] = '';
                bestScore = Math.min(score, bestScore);
            }
        }
        return bestScore;
    }
}

// Função que faz o movimento inteligente do Bot
function botMove() {
    let bestScore = -Infinity;
    let move;
    for (let i = 0; i < board.length; i++) {
        if (board[i] === '') {
            board[i] = 'O';
            let score = minimax(board, 0, false);
            board[i] = '';
            if (score > bestScore) {
                bestScore = score;
                move = i;
            }
        }
    }

    // Faz o movimento do Bot
    board[move] = 'O';
    cells[move].textContent = 'O';
    checkResult();
}

// Função que verifica o vencedor e retorna uma pontuação
function checkWinner() {
    for (let i = 0; i < winConditions.length; i++) {
        const winCondition = winConditions[i];
        const a = board[winCondition[0]];
        const b = board[winCondition[1]];
        const c = board[winCondition[2]];
        
        if (a === '' || b === '' || c === '') continue;

        if (a === b && b === c) {
            if (a === 'O') return 10; // Bot ganha
            if (a === 'X') return -10; // Jogador ganha
        }
    }
    
    if (!board.includes('')) {
        return 0; // Empate
    }

    return null; // O jogo continua
}

function handleCellClick(e) {
    const cellIndex = e.target.getAttribute('data-index');

    if (board[cellIndex] !== '' || !gameActive) return;

    updateCell(e.target, cellIndex);
    checkResult();

    if (isBotGame && gameActive) {
        setTimeout(botMove, 500); // Pequeno delay para o movimento do Bot
    }
}

function updateCell(cell, index) {
    board[index] = currentPlayer;
    cell.textContent = currentPlayer;
}

function checkResult() {
    let result = checkWinner();
    
    if (result === 10) {
        statusText.textContent = `Bot wins!`;
        gameActive = false;
    } else if (result === -10) {
        statusText.textContent = `Player wins!`;
        gameActive = false;
    } else if (result === 0) {
        statusText.textContent = `It's a draw!`;
        gameActive = false;
    } else {
        switchPlayer();
    }
}

function switchPlayer() {
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    statusText.textContent = `It's ${currentPlayer}'s turn`;
}

function restartGame() {
    currentPlayer = 'X';
    gameActive = true;
    board = ['', '', '', '', '', '', '', '', ''];
    statusText.textContent = `It's ${currentPlayer}'s turn`;
    cells.forEach(cell => cell.textContent = '');
}

cells.forEach(cell => cell.addEventListener('click', handleCellClick));
restartBtn.addEventListener('click', restartGame);

// Modo contra o Bot
vsBotBtn.addEventListener('click', () => {
    isBotGame = true;
    startGame();
});

// Modo 1v1 entre jogadores
vsPlayerBtn.addEventListener('click', () => {
    isBotGame = false;
    startGame();
});

// Iniciar o jogo
function startGame() {
    menu.style.display = 'none';
    gameContainer.style.display = 'block';
    restartGame();
}