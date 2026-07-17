-- calculate how fast
-- 20/s

local Serial = require('periphery').Serial
local f = Serial("/dev/ttyACM0", 9600)

local X = string.char(0x88)

local old = math.floor(os.clock() * 1000)
local n = 0

while true do
    local now = math.floor(os.clock() * 1000)
    if now-old > 5000 then
        break
    end
    n = n + 1
    local c = f:read(1)
    while c ~= X do
        c = f:read(1)
    end

    local s = ""
    while string.len(s) < 23 do
        local c = f:read(1, 0)
        if c ~= '' then
            s = s .. c
        end
    end

    local byt = string.byte(string.sub(s,8,8))
    local num = math.floor((tonumber(string.sub(s,9,12))+5) / 10)
    local dir = (byt == 66) and 'inb' or 'out'
    print(dir, num)
end

print(n)

f:close()
