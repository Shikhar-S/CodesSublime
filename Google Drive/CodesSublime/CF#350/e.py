
def delt(c,strn):
	t=c-1
	start=0
	end=len(strn)
	cnt=0
	#print c
	if(strn[t]=='('):
		start=t
		
		for i in range(start,len(strn)):
			if strn[i]=='(':
				cnt+=1
			else:
				cnt-=1
			if cnt==0: 
				end=i+1
				break
	else:
		end=t
		
		for i in xrange(end,-1,-1):
			if strn[i]=='(':
				cnt+=1
			else:
				cnt-=1
			if cnt==0:
				start=i
				break
		end=end+1
	l=len(strn)
	strn=strn[0:start]+strn[end:l]
	#print start, end
	if end!=l:
		c=start
	else:
		c=start-1
	c+=1
	return c,strn


if __name__ == "__main__":
	a,b,c=raw_input().split(' ')
	a=int(a)
	b=int(b)
	c=int(c)
	strn=raw_input()
	instruction=raw_input()
	for i in range(0,b):
		x=instruction[i]
		if x=='R' and c<a-1:
			c+=1
		elif x=='L' and c>1:
			c-=1
		elif x=='D':
			#print c
			c,strn=delt(c,strn)
	print strn

