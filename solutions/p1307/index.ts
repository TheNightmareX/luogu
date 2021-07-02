async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const raw: number = await new Promise((r) =>
    process.stdin.once("data", (raw: string) => r(parseInt(raw)))
  );

  const isNegative = raw < 0;
  // Must be positive
  const reversed = parseInt(String(raw).split("").reverse().join(""));
  const result = isNegative ? -reversed : reversed;

  console.log(result);
}

main();

export {};
