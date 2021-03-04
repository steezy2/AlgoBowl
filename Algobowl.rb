def create_input(n)
  outputarr = []
  max = rand(1000)
  value = 2
  for i in 1..n do
    max = rand(7000000)
    value = rand(value..max+value)
    line = "#{value}"
    outputarr << line
  end
  outputarr
end

def verfier(filename)
  file_data = File.read(filename).split("\n")

  n = file_data[0]
  validnums = [1]
  additions = file_data.drop(1)
  
  goodout = true
  
  failindex = -1
  
  index = 0
  
  
  if additions.length != n.to_i
    goodout = false
  end
  
  additions.each{ |line| 
    index += 1
    test = line.split(" ")
    if test.length != 2
      goodout = false
    end
  
    unless validnums.include? test[0].to_i
      goodout = false
    end
  
    unless validnums.include? test[1].to_i
      goodout = false
    end
  
    sum = test[0].to_i+test[1].to_i
    validnums << sum
    if !goodout
      failindex = index
      break
    end
  
  }
  
  if goodout
    puts "#{filename} file has passed"
  else
    puts "#{filename} has failed at line #{failindex+1}"
  end
end

=begin
This if for input creation


n = 500

inputarr = create_input(n)

inputarr.each { |x| puts x }
firstline = n.to_s+"\n"
File.open("Algoinput.txt", "w") { |f| f.write firstline
  f.write inputarr.join(" ") }
=end

file = "Algotestout.txt"
verfier(file)

