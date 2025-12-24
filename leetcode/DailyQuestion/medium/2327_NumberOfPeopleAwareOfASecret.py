class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        '''
        day[1] = A
        day[2] = prev
        day[3] = A, B (day[1 + 2])
        day[4] = A, C (B)
        day[5] = B, D (C) (day[4] - day[5-1]) + (day[3] - day[5-1])
        day[6] = 
        '''
        MOD = 10**9 + 7
        cnt = [0 for i in range(n+1)]
        cnt[1] = 1
        for d in range(1, n):
            for i in range(d + delay, d + forget):
                if i <= n:
                    cnt[i] += (cnt[d] % MOD)
                    cnt[i] %= MOD
            if d + forget <= n:
                cnt[d] = 0
        return sum(cnt) % MOD
