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
  const [, numbers] = await parseInput();

  let pickedNumbers: Set<number> = new Set();
  for (let i1 = 0; i1 < numbers.length - 1; i1++) {
    for (let i2 = i1 + 1; i2 < numbers.length; i2++) {
      const sum = numbers[i1] + numbers[i2];
      if (numbers.includes(sum)) pickedNumbers.add(sum);
    }
  }

  console.log(pickedNumbers.size);
}

main();
