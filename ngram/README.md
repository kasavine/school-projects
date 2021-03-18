# ngram

It will count the number of occurrences per character.
```
ngram [--fullstat] text [text2, text3]
```

### Examples
```
ngram "abcdef" "defg"
a:1
b:1
c:1
d:2
e:2
f:2
g:1

ngram "        "
 :8
```

--fullstat --> display the percentage of occurrence (Doesn't work yet.)
```
ngram --fullstat "aaabb"
a:3(60%)
b:2(40%)
```