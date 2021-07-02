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
  const [[consumerCount, maxActive], consumerQueue] = await parseInput();

  let ans = 0;

  const activeConsumers: number[] = [];
  while (consumerQueue.length || activeConsumers.some((v) => v)) {
    for (let i = 0; i < maxActive; i++) {
      if (!activeConsumers[i] && consumerQueue.length)
        activeConsumers[i] = consumerQueue.shift()!;
      if (activeConsumers[i]) activeConsumers[i]--;
    }
    ans++;
  }

  console.log(ans);
}

main();

export {};
