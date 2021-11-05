#include <string>
#include <iostream>
#include <functional>
using namespace std;

class MailService
{
  class Email {
  public:
    string from, to, subject, body;
  };
public:
  class EmailBuilder{
    Email& email;
  public:
    explicit EmailBuilder(Email &email) : email(email) {}

    EmailBuilder& from(string from)
    {
      email.from = from;
      return *this;
    }

    EmailBuilder& to(string to)
    {
      email.to = to;
      return *this;
    }

    EmailBuilder& subject(string subject)
    {
      email.subject = subject;
      return *this;
    }

    EmailBuilder& body(string body)
    {
      email.body = body;
      return *this;
    }
  };

  void send_email(function<void(EmailBuilder&)> builder)
  {
    Email email;
    EmailBuilder b{email};
    builder(b);
    send_email_impl(email);
  }
private:
  void send_email_impl(const Email& email)
  {
    // actually send the email
    cout << "Sending email from " << email.from << "\n"
      << "to: " << email.to << "\n"
      << "subj: " << email.subject << "\n"
      << "body: " << email.body << "\n";
  }
};

int main()
{
  MailService ms;
  ms.send_email([&](auto& eb) {
    eb.from("foo@bar.com")
      .to("bar@baz.com")
      .subject("hello")
      .body("Hello, how are you?");
  });
//  Sending email from foo@bar.com
//  to: bar@baz.com
//  subj: hello
//  body: Hello, how are you?
}