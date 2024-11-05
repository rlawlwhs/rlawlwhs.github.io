local tcp_port_field = Field.new("tcp.port")

local TCPPorts = {}
TCPPorts.__index = TCPPorts

function TCPPorts.new()
	local self = setmetatable({}, TCPPorts)
	return self
end

function TCPPorts:run()
	print("TCP PORTS RUN")

	local tw = TextWindow.new("TCP PORTS")

	local ports = {}
	local tap = Listener.new(nil, "tcp");
	

	local function remove()
		tap:remove()
	end

	tw:set_atclose(remove)

	function tap.packet(pinfo, tvb)
		local src_port = pinfo.src_port
		local dst_port = pinfo.dst_port
		if ports[src_port] then
			ports[src_port] = ports[src_port] + 1
		else	
			ports[src_port] = 1
		end
		if ports[dst_port] then
			ports[dst_port] = ports[dst_port] + 1
		else	
			ports[dst_port] = 1
		end
	end

	function tap.reset()
		tw:clear()
		ports = {}
	end
	
	function tap.draw(t)
		tw:clear()
		
		local sorted_ports = {}
		for port, count in pairs(ports) do
			table.insert(sorted_ports, {port = port, count = count})
		end
		
		table.sort(sorted_ports, function(a, b) return a.count > b.count end)
		
		for _, entry in pairs(sorted_ports) do
			tw:append("P "..entry.port.."\tC "..entry.count.."\n");
		end
	end

	retap_packets()
end

local function menuable_tap()
	local wnd = TCPPorts.new()
	wnd.run()
end

--local a = TCPPorts.new()
--a.run()

register_menu("Analyze/TCP Ports", menuable_tap, MENU_TOOLS_UNSORTED)
