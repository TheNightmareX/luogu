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

function getSuiteCost(count: number, cost: number, target: number) {
  let suiteCount;
  for (suiteCount = 1; suiteCount * count < target; suiteCount++);
  return suiteCount * cost;
}

async function main() {
  const [[target], ...suites] = await parseInput();
  const suiteCosts = suites.map(([count, cost]) =>
    getSuiteCost(count, cost, target)
  );
  console.log(Math.min(...suiteCosts));
}

main();

export {};
