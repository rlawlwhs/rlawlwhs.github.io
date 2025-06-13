  $(function() {
    $.get("/data.csv", function(data) {
      console.log('hello')
      const lines = data.trim().split("\n").slice(1); // 헤더 제외
      lines.forEach(line => {
        const [name, price] = line.split(",");
        $("#product-list").append(`<li>${name} - ${price}원</li>`);
      });
    });
  });
