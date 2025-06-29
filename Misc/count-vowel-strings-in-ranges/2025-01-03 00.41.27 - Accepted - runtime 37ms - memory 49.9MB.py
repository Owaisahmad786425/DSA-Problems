class Solution(object):
    def vowelStrings(self, w, q):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        # ans = []
        v = ['a','e','i','o','u']
        # for i in q:
        #     count=0
        #     for j in range(i[0], i[1]+1):
        #         temp = w[j]
        #         if temp[0] in v and temp[len(temp)-1] in v:
        #             count+=1
        #     ans.append(count)
        # return ans

        arr = [0]*len(w)
        ans = []
        if w[0][0] in v and w[0][len(w[0])-1] in v:
            arr[0] = 1
        for i in range(1, len(w)):
            if w[i][0] in v and w[i][len(w[i])-1] in v:
                arr[i] = arr[i-1] + 1
            else:
                arr[i] = arr[i-1]
            
        for i in q:
            start = i[0]
            end = i[1]
            if start==0:
                ans.append(arr[end])
            elif start == end:
                if w[start][0] in v and w[end][len(w[start])-1] in v:
                    ans.append(1)
                else:
                    ans.append(0)
            else:
                ans.append(arr[end]-arr[start-1])
        return ans







        