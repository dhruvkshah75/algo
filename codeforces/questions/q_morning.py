t = int(input())
for _ in range(t):
    pin_code = input()
    ans = 0
    cur_pos = 1
    for i in range(4):
        if(int(pin_code[i]) == 0):
            ans += abs(10 - cur_pos) + 1
            cur_pos = 10
        else:
            ans += abs(int(pin_code[i]) - cur_pos) + 1
            cur_pos = int(pin_code[i])
    print(ans)