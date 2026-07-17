local f = assert(io.open("/dev/ttyACM0",'r'))
while true do
    local c = f:read(1)
    if c then
        print(c)
    end
end
