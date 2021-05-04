first = int(input())
second = int(input())
summ = 0
list = []
list.append(first)
list.append(second)

def function(total):
    global first, second, summ
    total = first - second
    first = second
    second = total
    if total < 0:
        return total
    else:
        list.append(total)
        function(total)


function(0)
print(len(list))