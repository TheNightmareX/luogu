async function main() {
  process.stdin.resume();
  process.stdin.setEncoding("utf-8");
  const totalDays: number = await new Promise((r) =>
    process.stdin.once("data", (raw: string) => r(parseInt(raw)))
  );

  let ans = 0;
  let day = 0;
  let restDays = 0;
  let duration = 0;
  do {
    if (!restDays) restDays = ++duration;
    day++, restDays--;
    ans += duration;
  } while (day < totalDays);

  console.log(ans);
}

main();
