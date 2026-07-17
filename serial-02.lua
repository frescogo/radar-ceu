local Serial = require('periphery').Serial

-- Open /dev/ttyUSB0 with baudrate 115200, and defaults of 8N1, no flow control
local serial = Serial("/dev/ttyACM0", 9600)

local n = 0
while true do
    local c = serial:read(1, 0)
    if c == '' then
        n = n + 1
    else
        print('c', n, c)
    end
end

serial:close()
