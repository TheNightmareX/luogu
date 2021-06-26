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
  const [[, maxRange], values] = await parseInput();
  /**中间段的最大sum，右端的sum减去左端前一位的sum即中间段的sum */
  let answer: number = -Infinity;
  /**sums[i]表示从values[0]到values[i]的sum */
  const sums: number[] = [];
  /**范围内的有效sum的indexes，按sum的大小从小到大排序 */
  let effectiveSumIndexes: number[] = [];

  for (let index = 0; index < values.length; index++) {
    const sum = (sums[index - 1] ?? 0) + values[index];
    sums[index] = sum;
    effectiveSumIndexes.push(index);

    // 维护有效sum列表的有效性和有序性
    effectiveSumIndexes = effectiveSumIndexes.filter(
      // 移除超出范围的sum的index，由于需要减去的是左端前一位的sum，故使用 `<`
      // 移除比当前sum更大（使中间段的sum更小且存活时间更短，无用了）的sum的index
      (sumIndex) => !(sumIndex < index - maxRange) && !(sums[sumIndex] > sum)
    );

    const bestLeftSum = sums[effectiveSumIndexes[0]];
    answer = Math.max(answer, sums[index] - bestLeftSum);

    // console.debug(index, sums, effectiveSumIndexes);
  }

  console.log(answer);
}

main();

export {};
