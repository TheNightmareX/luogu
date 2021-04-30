async function parseInput() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const input: number[][] = await new Promise((resolve) =>
    process.stdin.on("data", (raw: string) =>
      resolve(
        raw.split("\n").map((line) => line.split(" ").map((s) => parseFloat(s)))
      )
    )
  );
  return input;
}

async function main() {
  const [scores] = await parseInput();
  const scaledScores = scores.map((v) => v / 10);
  const ans = scaledScores[0] * 2 + scaledScores[1] * 3 + scaledScores[2] * 5;
  console.log(ans);
}

main();

export {};
