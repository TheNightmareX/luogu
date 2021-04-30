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
  const [[min, max]] = await parseInput();
  let ans = 0;

  for (let v = min; v <= max; v++) {
    String(v)
      .split("")
      .forEach((s) => (s == "2" ? ans++ : undefined));
  }

  console.log(ans);
}

main();

export {};
