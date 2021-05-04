var NUM : int
var sum : int := 0
get NUM

if NUM = 10 then
    sum := sum + 1
elsif NUM = 9 then
    sum := sum + 1
elsif NUM = 8 then
    sum := sum + 2
elsif NUM = 7 then
    sum := sum + 2
elsif NUM = 6 then
    sum := sum + 3
elsif NUM = 5 then
    sum := sum + 3
elsif NUM = 4 then
    sum := sum + 3
elsif NUM = 3 then
    sum := sum + 2
elsif NUM = 2 then
    sum := sum + 2
elsif NUM = 1 then
    sum := sum + 1
end if
put sum