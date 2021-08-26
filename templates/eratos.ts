/**
 * 求素数：埃氏筛法
 * @param maxNum
 * @returns
 */
function eratos(maxNum: number) {
  const exclusionSet = new Set<number>([0, 1]);
  const primeSet = new Set<number>();

  const INITIAL_PRIME = 2;
  for (let curNum = INITIAL_PRIME; curNum <= maxNum; curNum++) {
    if (exclusionSet.has(curNum)) continue;
    const primeNum = curNum;
    primeSet.add(primeNum);
    if (primeNum ** 2 > maxNum) continue;
    for (
      let multiple = primeNum * 2;
      multiple <= maxNum;
      multiple += primeNum
    ) {
      exclusionSet.add(multiple);
    }
  }

  return primeSet;
}

console.log(eratos(100));

export {};
