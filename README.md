# alidns_sign
这是一个C语言编写的程序，生成带签名的阿里云DNS解析的请求字符串。
签名算法HMAC-SHA1，BASE64。
传入两个参数，HTTP请求字符串，你的阿里云secert key。输出带上签名参数的HTTP请求字符串。
