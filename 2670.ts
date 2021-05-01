async function getInputLines(): Promise<string[]> {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const raw: string = await new Promise((r) => process.stdin.once("data", r));
  const lines = raw
    .trimEnd()
    .split("\n")
    .map((line) => line.trimEnd());
  return lines;
}

function walkAround<T>(
  matrix: T[][],
  position: [number, number],
  onField: (field: T) => any
) {
  for (let row = position[0] - 1; row <= position[0] + 1; row++) {
    if (matrix[row] == null) continue;
    for (let col = position[1] - 1; col <= position[1] + 1; col++) {
      const field = matrix[row][col];
      if (field == null) continue;
      onField(field);
    }
  }
}

async function main() {
  const inputLines = await getInputLines();
  const [maxRows, maxCols] = inputLines[0].split(" ").map((v) => +v - 1);
  const matrix = inputLines.slice(1).map((line) => line.split("")) as (
    | "*"
    | "?"
  )[][];

  const resultMatrix: ("*" | number)[][] = [];
  for (let row = 0; row <= maxRows; row++) {
    resultMatrix[row] = [];
    for (let col = 0; col <= maxCols; col++) {
      const field = matrix[row][col];
      if (field == "*") {
        resultMatrix[row][col] = "*";
      } else {
        let result = 0;
        walkAround(matrix, [row, col], (v) => {
          if (v == "*") result++;
        });
        resultMatrix[row][col] = result;
      }
    }
  }

  console.log(resultMatrix.map((line) => line.join("")).join("\n"));
}

main();

export {};
