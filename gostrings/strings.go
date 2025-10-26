package strings

func Reverse(s string) string{
	str := ""
	for _, c := range s{
		str = string(c) + str
	}
	return str
}