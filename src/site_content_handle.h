#include <string>

namespace site {

  class site_content_handler {
    private:
      std::string news_list_url;

    public:
      const std::string * const content() const;
      void operator()();

      ~site_content_handler();
      site_content_handler(std::string url) : news_list_url(url){
      }
  };

}
