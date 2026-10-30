class Solution:
    def simplifyPath(self, path: str) -> str:
        arr = path.split('/')
        stack = []

        for i in arr:
            if i == '' or i == '.':
                continue

            elif i == '..':
                if stack:
                    stack.pop()

            else:
                stack.append(i)

        return '/' + '/'.join(stack)