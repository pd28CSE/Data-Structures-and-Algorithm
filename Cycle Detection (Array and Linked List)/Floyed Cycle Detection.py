def floyedCycleDetection(li: list[int]) -> int:

    slow = li[0]
    fast = li[0]

    while True:
        slow = li[slow]

        # Hare moves with twice, the speed of fast
        fast = li[li[fast]]
        if slow == fast:
            break
    
    slow = li[0]

    while slow != fast:
        slow = li[slow]
        fast = li[fast]

    return slow


li = [2, 6, 4, 6, 3, 1, 5]
print(floyedCycleDetection(li))