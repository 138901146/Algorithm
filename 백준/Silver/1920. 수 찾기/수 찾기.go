package main

import (
  "bufio"
  "fmt"
  "os"
  "sort"
)

func find(nums *[]int, target, startIdx,finIdx int) int {
    for startIdx <= finIdx {
        targetIdx := (startIdx + finIdx) >> 1

        if (*nums)[targetIdx] == target {
            return 1
        } else if (*nums)[targetIdx] < target {
            startIdx = targetIdx + 1
        } else {
            finIdx = targetIdx - 1
        }
    }
  return 0
}

func main() {
    rx := bufio.NewReader(os.Stdin)
    tx := bufio.NewWriter(os.Stdout)

    defer tx.Flush()

    var n, m, target int
    fmt.Fscanln(rx, &n)
    nums := make([]int,n)

    for i:=0;i<n;i++{
        fmt.Fscan(rx, &nums[i])
    }
    fmt.Fscanln(rx)

    sort.SliceStable(nums, func(i, j int) bool {
        return nums[i] < nums[j]
    })

    fmt.Fscanln(rx, &m)
    for i:=0;i<m;i++{
        fmt.Fscan(rx, &target)
        fmt.Fprintln(tx, find(&nums, target, 0, n-1))
    }
}