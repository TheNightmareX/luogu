async function parseInput() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const input: number[][] = await new Promise((resolve) =>
    process.stdin.on("data", (raw: string) =>
      resolve(
        raw
          .trim()
          .split("\n")
          .map((line) => line.split(" ").map((s) => parseFloat(s)))
      )
    )
  );
  return input;
}

async function main() {
  const [[totalAmount, requireAmount], ...scoreTable] = await parseInput();

  const sortedScoreTable = scoreTable.sort(
    ([id1, score1], [id2, score2]) => -(score1 - score2) || id1 - id2
  );

  const scoreLine = sortedScoreTable[Math.floor(requireAmount * 1.5) - 1][1];
  const firstUnqualifiedIndex = scoreTable.findIndex(
    ([, score]) => score < scoreLine
  );
  const qualified = scoreTable.slice(0, firstUnqualifiedIndex);

  console.log(scoreLine, qualified.length);
  console.log(qualified.map((arr) => arr.join(" ")).join("\n"));
}

main();

export {};
