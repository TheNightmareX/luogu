async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const input: string = await new Promise((resolve) =>
    process.stdin.on("data", (raw: string) => resolve(raw.trim()))
  );

  let ans = 0;

  for (let i = 0; i < input.length; i++) if (input[i] == "1") ans++;

  console.log(ans);
}

main();

export {};
