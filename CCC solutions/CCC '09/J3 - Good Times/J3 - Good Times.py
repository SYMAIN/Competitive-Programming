t = input()

differences = ["0000","-300","-200","-100","0000","100","130"]
times = {
	"Ottawa":t,
	"Victoria":t,
	"Edmonton":t,
	"Winnipeg":t,
	"Toronto":t,
	"Halifax":t,
	"St. John's":t
}


for a, i in enumerate(times):
	time = str(times[i])
	diff = str(differences[a])
	HH,MM=0,0

	Mtime = time[-2:]
	Htime = time[0:-2]

	Mdiff = diff[-2:]
	Hdiff = diff[0:-2]

	if Htime == "":
		HH = 0 + int(Hdiff)
		MM = int(Mtime) + int(Mdiff)
	else:
		HH = int(Htime) + int(Hdiff)
		MM = int(Mtime) + int(Mdiff)

	if int(HH) < 0:
		HH = str(24+int(HH))
	
	HH=int(HH)
	MM=int(MM)
	if (MM >= 60):
		HH += MM//60
		MM -= 60
	if HH >= 24:
		HH -= 24
		
	MM = str(MM) + "0" if len(str(MM)) == 1 else MM
	HH = "" if HH==0 else HH

	print(f"{HH}{MM} in {i}")