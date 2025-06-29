class Solution(object):
    def makeGood(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = 0
        temp = s
        while(i<len(temp)-1):
            if temp[i] != temp[i+1]:
                if temp[i].lower() == temp[i+1].lower():
                    temp = temp[:i] + temp[i+2:]
                    i-=1
                    if i<0:
                        i=0
                else:
                    i+=1
            else:
                i+=1
        return temp

        
        