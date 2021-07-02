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
  const [[maxDegree], numbers] = await parseInput();

  let result = "";
  for (let i = 0; i < numbers.length; i++) {
    const n = numbers[i];
    if (!n) continue;
    const absN = Math.abs(n);
    const degree = maxDegree - i;
    const symbol = n > 0 ? (result ? "+" : "") : "-";

    result += symbol;
    if (degree) {
      if (absN != 1) result += absN;
      result += "x";
      if (degree != 1) result += `^${degree}`;
    } else {
      result += absN;
    }
  }

  console.log(result);
}

main();

export {};
