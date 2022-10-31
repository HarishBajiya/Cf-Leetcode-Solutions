class Solution(object):
  def reverseString(self, s):
    """
    :type s: List[str]
    :rtype: None Do not return anything, modify s in-place instead.
    """
    begin = 0
    final = len(s)-1
    
    while begin < final:
        temp = s[begin]
        s[begin] = s[final]
        s[final] = temp
        
        begin += 1
        final -= 1
    
    return s