var Output : int
var Num : int
var Square : real

get Num

Square := sqrt (Num)

Output := round (Square)
if Output > Square then
    Output := Output - 1
end if

put "The largest square has side length ", Output, "."
