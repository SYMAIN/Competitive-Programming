var SpeedLimit : int
var RecordedSpeed : int
var Total : int 

get SpeedLimit
get RecordedSpeed

if SpeedLimit - RecordedSpeed  >= 0 then
    put "Congratulations, you are within the speed limit!"
elsif SpeedLimit - RecordedSpeed  <= -1 and SpeedLimit - RecordedSpeed  >= -20 then
    put "You are speeding and your fine is $100."
elsif SpeedLimit - RecordedSpeed  <= -21 and SpeedLimit - RecordedSpeed  >= -30 then
    put "You are speeding and your fine is $270."
elsif SpeedLimit - RecordedSpeed  <= -31 then
    put "You are speeding and your fine is $500."
end if