
1." n & (n-1) will remove the right most set bit "
eg
n  = 6 = (0110)
         n - 1 = 5 = (0101)
                     -- (underlining the converted bits)
                     n  = 12 = (1100)
                               n - 1 = 11 = (1011)
                                               -- - (underlining the converted bits)
                                               notice to get n - 1 we reverse all bits starting from the "right most set bit" to all bits in right
                                               now:
                                               n & (n - 1) will remove the right most set bit
                                               (0110) & (0101) = (0100)
                                                               'qusetion on this:'
                                                               (a) wap to count the number of ones in binary reperesentation of a number
                                                               (b) wap to check if a given number is power of '2'
                                                               video: 14.3 veryyy important of apna college

