/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let rows = Array(3).fill(0);
    let cols = Array(3).fill(0);
    let diag = 0, antiDiag = 0;

    for(let i = 0; i < moves.length; i++){
        let [r,c] = moves[i];
        let player = (i % 2 === 0) ? 1 : -1;

        rows[r] += player;
        cols[c] += player;
        if(r === c) diag += player;
        if(r+c === 2) antiDiag += player;

        if(Math.abs(rows[r]) === 3 ||
            Math.abs(cols[c]) === 3 ||
            Math.abs(diag) === 3 ||
            Math.abs(antiDiag) === 3){
                return player === 1 ? "A" : "B";
            }
    }
    return moves.length === 9 ? "Draw" : "Pending";
};