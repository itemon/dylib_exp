#include <iostream>
#include "site_content_handle.h"

namespace site {
  const std::string * const site_content_handler::content() const {
    return const_cast<const std::string * const>(&news_list_url);
  }

  void site_content_handler::operator()() {
    std::cout << "handle content parsing " << std::endl;
  }

  site_content_handler::~site_content_handler() {
    std::cout << "destructing site content handler" << std::endl;
  }
}
