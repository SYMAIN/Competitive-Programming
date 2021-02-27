txt_diction = {'CU': 'see you', ':-)': "I'm happy", ':-(': "I'm unhappy", ';-)': 'wink', ':-p': 'stick out my tongue', '(~.~)': 'sleepy', 'TA': 'totally awesome', 'CCC': 'Canadian Computing Competition', 'CUZ': 'because', 'TY': 'thank-you', "YW": "you're welcome", 'TTYL': 'talk to you later'}

while 1:
	word = input()
	if word in txt_diction.keys():
		print(txt_diction[word])
	else:
		print(word)
	
	if word == "TTYL":
		break