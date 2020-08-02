/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

let str;
function initialize(s) {
    // This function is called once before all queries.
    str = s;
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

const MODULO = 1000000007;

const factorialModulo = num => {
    let ans = 1;
    while (num > 1) {
        ans *= num;
        ans %= MODULO;
        num--;
    }

    return ans;
}

function answerQuery(l, r) {
    // Return the answer for this query modulo 1000000007.
    const map = {};

    for (let i = l - 1; i < r; i++) {
        if (!map[str.charAt(i)]) {
            map[str.charAt(i)] = 1;
        } else {
            map[str.charAt(i)]++;
        }
    }

    const candidates = Object.entries(map).filter(([key, val]) => val >= 2)
    const singledCandidates = candidates.map(([key, val]) => [key, Math.floor(val / 2)])

    const subseqLength = singledCandidates.reduce((acc, [key, val]) => acc + val, 0);
    const factorials = singledCandidates.map(([key, val]) => factorialModulo(val))

    return factorials.reduce((acc, curr) => acc / curr, factorialModulo(subseqLength)) * ((r - l + 1) - (subseqLength * 2));
}

let s = "week"
initialize(s);
console.log(answerQuery(1, 4));